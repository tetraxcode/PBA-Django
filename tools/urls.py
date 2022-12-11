from django.urls import path
from . import views
from register import views as v 

urlpatterns = [
    path('', views.home, name = 'zytools-home'),
    path('about/', views.about, name = 'zytools-about'),
    path('register/', v.register, name = 'zytools-register'),
    path('login/', v.login, name='zytools-login'),
    path('forgot-password', v.forgot_password, name='zytools-forgot-password'),
    path('view/<userid>/', views.view, name = 'zytools-view')
]