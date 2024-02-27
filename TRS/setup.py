from os import name
from setuptools import find_packages, setup

setup(
    name='flaskr',
    version='1.0.0',
    packages=find_packages(),
    # include_package_data=True,
    zip_safe=False,
    install_requires=[
        'Flask>=1.1.2',
        'Flask-SQLAlchemy>=2.5.1',
        # 'kafka-python>=2.0.2',
        # 'numpy',
        'pandas',
        # 'psycopg2',
        'psycopg2-binary',
        'scikit-learn',
        'SQLAlchemy>=1.4.5',
        'SQLAlchemy-Utils>=0.36.8',
        'python-dotenv>=0.15.0',
        'gunicorn>=20.1.0',
        # 'Flask-Migrate>=2.7.0',
        'Flask-Cors',
        'pytest==6.2.5',
        'scikit-learn',
        'scikit-surprise',
        'APScheduler'
    ],
)