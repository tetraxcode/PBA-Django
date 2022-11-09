# PBA-Django
This tool is designed and developed by Abhinav Reddy, if you have any questions, reach out to him at apall009@ucr.edu

Prerequisites: 
1. Latest version of python. You can find it <a href="https://www.python.org/downloads/">here</a>
2. Packages specified in requirements.txt which will be installed in steps to run

Steps to run: 
1. Click on the code button in green and download the repository as zip and extract it in your desired location, fire up terminal and navigate to the project directory (More advanced users can use ```git clone <link to this repo>```)
2. A virtual environment is recommended but not required
   Steps to set up a virtual environment:
   1. Navigate to the downloaded project folder and run the command ```python3 -m venv <name of environment>``` <br/>
      for example ```python3 -m venv env```
   2. You should see a folder env in your project directory, then run the command ```source env/bin/activate```
3. Then run the command ```pip install -r requirements.txt``` (if you are experiencing error try running ```python -m pip cache purge``` before ```pip install -r requirements.txt```
4. Once its done, run the command ```python manage.py migrate```
5. Once migrations are done, run the command ```python manage.py runserver```
6. Navigate to ```http://localhost:8000```, register an account, login and have fun using the tool!!# PBA-Django
