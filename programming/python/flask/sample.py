import flask
app = flask.Flask(__name__)


@app.route('/')
def hellow_world():
    return "<p>hi</p>"
