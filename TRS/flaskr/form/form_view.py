import logging
from flask import Blueprint, request, Response
from flask.globals import current_app
from flask.json import jsonify
from flaskr.utils.file import File
from constants import FILE_LIST_STUDENTS_PATH
from werkzeug.utils import secure_filename
import os
from flaskr.utils.time import timeNow
from flaskr.form.form_model import Form
import pandas as pd

blueprint = Blueprint('form', __name__)

@blueprint.route('/api/saveform', methods=['POST',])
def save_form():
    data = request.json
    # Kiểm tra xem dữ liệu có tồn tại không
    if data:
        student_id = data.get('student_id')
        list_used_tcids = data.get('list_used_tcids')
        time_ordered_tcids = data.get('time_ordered_tcids')
        scores = data.get('scores')
        
        form = Form(student_id=student_id, list_used_tcids=list_used_tcids, time_ordered_tcids=time_ordered_tcids, scores=scores)
        form.save()

        return jsonify({"message": "Data received successfully"})
    else:
        # Trả về một phản hồi lỗi nếu dữ liệu không tồn tại
        return jsonify({"error": "No data received"})
