#imports
from flask import Flask, request, render_template
import requests
import sys

# site: http://localhost:5000/

sys.stderr = open('log.txt', 'w')

    
# initialisations
app = Flask(__name__, static_url_path='/static')
ORG_NAME = 'google'
m=0
sorted_repos=[]

@app.route('/')
def display():
    # Render the front page with the form   
    return render_template('form.html')

@app.route('/<element>',methods=['POST','GET'])
def display_element(element):
    global sorted_repos
    global m
    global ORG_NAME
    ORG_NAME.lstrip()
    ORG_NAME.rstrip()

    ele=int(element)-1
    repo_name = str(sorted_repos[ele][1])
    
    repo_name.lstrip()
    repo_name.rstrip()
    
    #get the forks
    url = f'https://api.github.com/repos/{ORG_NAME}/{repo_name}/forks'

    #parameters to sort by oldest
    params = {'sort': 'oldest', 'per_page': m}

    #send get request and retrieve data
    response = requests.get(url,params)
    
    #initialise
    top_forks=[]
    text='The  oldest forks are:'

    #in case the get request fails due to excessive number or forks
    if response.status_code!=200 :
        text='Sorry! Too many forks to sort by oldest! Following are the newest forks instead:'
        params = {'sort': 'newest', 'per_page': m}
        response = requests.get(url,params)

    response=response.json()
    for fork in response:
        
        if type(fork)==type('hi'):
            return render_template('error.html',text='Limit exceeded! Either the number of forks or number of repositories was too high so the operation failed.')

        s=fork['created_at']
        top_forks.append((fork['owner']['login'],s[11:-1],s[:10]))
        
    else:

        return render_template('element.html',text=text, elements=top_forks)





@app.route('/result',methods=['POST','GET'])
def  getRepo():
    global sorted_repos
    global m
    global ORG_NAME
    url = 'https://api.github.com/search/repositories'

    ORG_NAME=request.form.get('org_name')
    n=request.form.get('n')
    
    m=request.form.get('m')
    # Get the organization object
    n=int(n)

    m=int(m)
    if (n<=0):
        return render_template('error.html',text='Invalid number of repos entered! Please enter a positive number.')
    if (m<=0):
        return render_template('error.html',text='Invalid number of forks entered! Please enter a positive number.')

    # org = g.get_organization(ORG_NAME)
    params = {'q': f'user:{ORG_NAME}', 'sort': 'forks', 'order': 'desc', 'per_page': n}
    
    
    #try to send get request
    try:
        response = requests.get(url,params)
    
    
        sorted_repos=[]

    
        result=response.json()['items']
    

        for i in range(n):
            sorted_repos.append((i+1,result[i]["name"],result[i]["forks"]))

    #request fails if invalid name
    except:
        return render_template('error.html',text='Error! Either the organisation name is invalid, or number of repositories was too high! Please try again.')
   
    return render_template('result.html',org_name=ORG_NAME,m=m,n=n,elements=sorted_repos)

if __name__ == '__main__':
    app.run(debug=False)
    
