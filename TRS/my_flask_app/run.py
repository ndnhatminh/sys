# run.py
from app import create_app
from app.models import db, User

app = create_app()

if __name__ == '__main__':
    with app.app_context():
        db.create_all()

        # Create a user
        user = User(username='john_doe')
        user.save()

        # Update the user
        user.update(username='updated_username')
        user.save()

        # Delete the user
        user.delete(commit=True)

        # Query all users
        all_users = User.query.all()
        print(all_users)
