from django.shortcuts import redirect, render
from markupsafe import re
from .forms import RegisterForm
from django.contrib.auth import authenticate, login as auth_login
from django.contrib.auth.models import User
# Create your views here.

def register(response):
    if response.method == 'POST':
        form = RegisterForm(response.POST)
        if form.is_valid():
            form.save()
        return redirect('/')
    else:
        form = RegisterForm()
    return render(response, 'register/register.html', {'form':form})

def login(request):
    if request.method == "POST":
        print(request.POST)
        username = request.POST['username']
        password = request.POST['password']
        user = authenticate(request, username=username, password=password)

        if user is not None:
            auth_login(request, user)
            return redirect('/')
        else:
            return render(request, 'login/login.html', {'message': 'Invalid username/password'})
    # return render(request, 'todo/login.html', {'form': form})
    return render(request, 'login/login.html')

def forgot_password(request):
    if request.method == "POST":
        email = request.POST['email']
        user_exist = User.objects.filter(email=email).exists()
        if user_exist:
            pass
        else:
            return render(request, 'register/forgot.html', {'message': "Email does not exist, please register to use this application"})
    return render(request, 'register/forgot.html')