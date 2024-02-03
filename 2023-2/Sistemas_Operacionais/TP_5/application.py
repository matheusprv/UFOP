from flask import Flask, request
app = Flask(__name__)

from flask_sqlalchemy import SQLAlchemy

app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///data.db'
db = SQLAlchemy(app)


class Departamento(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(80), unique = False, nullable = False)
    description = db.Column(db.String(120)) 

    def __repr__(self):
        return f"{self.id} - {self.name}: {self.description}"

# CREATE
@app.route('/')
def main_page():
    return "Hello World"

# CREATE
@app.route('/departamentos', methods=['POST'])
def add_departamento():
    name = request.json['name']
    description = request.json['description']
    new_departamento = Departamento(name = name, description = description)
    db.session.add(new_departamento)
    db.session.commit()
    return {'id': new_departamento.id}

# READ
@app.route('/departamentos', methods = ['GET'])
def get_departamentos():
    departamentos = Departamento.query.all()
    output = [{'id': departamento.id, 'name': departamento.name, 'description': departamento.description} for departamento in departamentos]
    return {"departamentos": output}

@app.route('/departamentos/<id>', methods = ['GET'])
def get_departamento(id):
    departamento = Departamento.query.get_or_404(id)
    return {'id': departamento.id, 'name': departamento.name, 'description': departamento.description}

# UPDATE
@app.route('/departamentos/<id>', methods=['PUT'])
def update_departamento(id):
    departamento = Departamento.query.get_or_404(id)
    data = request.json
    
    if 'name' in data: departamento.name = data['name']
    if 'description' in data: departamento.description = data['description']
    
    db.session.commit()

    return {"message": "Atualizado"}

# DELETE
@app.route('/departamentos/<id>', methods=['DELETE'])
def delete_departamento(id):
    departamento = Departamento.query.get(id)
    db.session.delete(departamento)
    db.session.commit()
    return {"message": "Departamento deleted"}


def createDatabase():
    with app.app_context():
        db.create_all()
        print(Departamento.query.all())

if __name__ == "__main__":
    createDatabase()
    app.run(debug=True, host='0.0.0.0', port=5000)
