from django.shortcuts import redirect, render
from markupsafe import re
from .forms import RegisterForm
from django.contrib.auth import authenticate, login as auth_login
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
        username = request.POST['username']
        password = request.POST['password']
        user = authenticate(request, username=username, password=password)

        if user is not None:
            auth_login(request, user)
            return redirect('/')
        else:
            return render(request, 'login/login.html', {'invalid': 'Invalid username/password'})
    # return render(request, 'todo/login.html', {'form': form})
    return render(request, 'login/login.html')