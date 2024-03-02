#!/bin/sh
gunicorn wsgi:app --timeout 600