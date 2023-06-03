from flask import Flask, render_template, jsonify, send_from_directory, request
import pymongo
import os
from bson import json_util

app = Flask(__name__)

# Set up MongoDB connection
client = pymongo.MongoClient('mongodb://localhost:27017/')
db = client['shelter_data']
collection = db['animal_shelter_data']

@app.route('/')
def index():
    return render_template('index1.html')

@app.route('/search', methods=['GET', 'POST'])
def search():
    if request.method == 'POST':
        # Handle the POST request and perform the search
        animal_type = request.form.get('animalType', '')
        animal_color = request.form.get('animalColor', '')
        outcome_type = request.form.get('outcomeType', 'All')
        sort_by = request.form.get('sortBy', 'animal_id')
        sort_order = request.form.get('sortOrder', 'asc')

        query = {}
        if animal_type != 'All':
            query['animal_type'] = animal_type
        if animal_color:
            query['color'] = animal_color
        if outcome_type != 'All':
            query['outcome_type'] = outcome_type

        results = collection.find(query).sort(sort_by, 1 if sort_order == 'asc' else -1)
        serialized_results = json_util.dumps(list(results))

        return serialized_results

    # Handle the GET request and render the search page
    return render_template('index1.html')

@app.route('/dog-breeds')
def dog_breeds():
    breeds = collection.distinct('breed', {'animal_type': 'Dog'})
    return jsonify(breeds)

@app.route('/cat-breeds')
def cat_breeds():
    breeds = collection.distinct('breed', {'animal_type': 'Cat'})
    return jsonify(breeds)

@app.route('/static/<path:filename>')
def serve_static(filename):
    root_dir = os.path.dirname(os.path.abspath(__file__))
    return send_from_directory(os.path.join(root_dir, 'static'), filename)

@app.route('/static/image/<path:filename>')
def serve_image(filename):
    root_dir = os.path.dirname(os.path.abspath(__file__))
    return send_from_directory(os.path.join(root_dir, 'static', 'image'), filename)

if __name__ == '__main__':
    app.run()

