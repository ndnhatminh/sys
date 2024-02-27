# app/models.py
from flask_sqlalchemy import SQLAlchemy
from flask_sqlalchemy.model import Model
from sqlalchemy.ext.declarative import declared_attr
from sqlalchemy.sql.sqltypes import DateTime
from sqlalchemy.sql import func
import uuid

db = SQLAlchemy(model_class=Model)

class CRUDMixin(Model):
    @declared_attr
    def id(cls):
        return db.Column(db.String(36), primary_key=True, default=str(uuid.uuid4()))

    @declared_attr
    def created_at(cls):
        return db.Column(DateTime(timezone=True), default=func.now())

    @declared_attr
    def updated_at(cls):
        return db.Column(DateTime(timezone=True), default=func.now(), onupdate=func.now())

    @declared_attr
    def deleted_at(cls):
        return db.Column(DateTime(timezone=True), default=None)

    @classmethod
    def create(cls, **kwargs):
        instance = cls(**kwargs)
        return instance.save()

    def update(self, commit=True, **kwargs):
        for attr, value in kwargs.items():
            setattr(self, attr, value)
        return commit and self.save() or self

    def save(self, commit=True):
        db.session.add(self)
        if commit:
            try:
                db.session.commit()
                return True
            except Exception as e:
                db.session.rollback()
                raise DBCommitException(e)

        return self

    def delete(self, hard_delete=False, commit=True):
        if hard_delete:
            db.session.delete(self)
            if commit:
                try:
                    db.session.commit()
                    return True
                except Exception as e:
                    db.session.rollback()
                    raise DBCommitException(e)
            return False
        else:
            return self.deleted_at is None and self.update(commit, deleted_at=func.now())

class User(db.Model, CRUDMixin):
    __tablename__ = 'users'
    username = db.Column(db.String(50), unique=True)
