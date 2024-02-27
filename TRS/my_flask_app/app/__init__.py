# app/__init__.py
from flask import Flask
from config import Config
from app.models import db

def create_app():
    app = Flask(__name__)
    app.config.from_object(Config)

    db.init_app(app)

    return app