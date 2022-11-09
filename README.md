# PBA-Django

Prerequisites: 
1. Latest version of python. You can find it <a href="https://www.python.org/downloads/">here</a>
2. Git (recommended)

Steps to run: 
1. Download the repo as a zip or navigate to wherever you want to save this project and run the command ```git clone <link to this repo>```
2. A virtual environment is recommended but not required
   Steps to set up a virtual environment:
   1. Navigate to the downloaded project folder and run the command ```python3 -m venv <name of environment>``` <br/>
      for example ```python3 -m venv env```
   2. You should see a folder env in your project directory, then run the command ```source env/bin/activate```
3. Then run the command ```pip install -r requirements.txt```
4. Once its done, run the command ```python manage.py migrate```
5. Once migrations are done, run the command ```python manage.py runserver```
<<<<<<< HEAD
6. Navigate to ```http://localhost:8000```, register an account, login and have fun using the tool!!# PBA-Django
=======
6. Navigate to ```http://localhost:8000```, register an account, login and have fun using the tool!!
>>>>>>> ce704b36a6fb6a2513542124d7ac994e9691acbe
