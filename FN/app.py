from flask import Flask, request, render_template, make_response
import sqlite3
import random

app = Flask(__name__)


@app.route('/login')
def login():
    if not ("login" in request.args and "password" in request.args):
        return render_template("login.html")
    try:
        SQL_string = "SELECT login FROM users WHERE login = '"
        SQL_string += request.args["login"]
        SQL_string += "' AND password = '"
        SQL_string += request.args["password"]
        SQL_string += "'"
        connection = sqlite3.connect("users")
        cursor = connection.cursor()
        cursor.execute(SQL_string)
    except:
        return render_template("login.html")
    result = cursor.fetchone()
    if not result:
        connection.close()
        return render_template("login.html")
    s = request.cookies.get('session')
    SQL_string = f"UPDATE session SET admin=1 WHERE s='{s}'"
    cursor.execute(SQL_string)
    connection.commit()
    connection.close()
    return render_template("home.html")


@app.route('/')
def home():
    if not request.cookies.get('session'):
        resp = make_response(render_template("home.html"))
        s = cookiegen()
        print(s)
        resp.set_cookie('session', s)
        SQL_string = f"INSERT INTO session (s, admin) VALUES('{s}', 0)"
        connection = sqlite3.connect("users")
        cursor = connection.cursor()
        cursor.execute(SQL_string)
        connection.commit()
        connection.close()
        return resp
    return render_template("home.html")


def cookiegen():
    random.seed()
    a = "s"
    for i in range(10):
        a += str(random.randint(0, 9))
    return a

@app.route('/archive')
def archive():
    s = request.cookies.get('session')
    SQL_string = f"SELECT admin FROM session WHERE s='{s}'"
    connection = sqlite3.connect("users")
    cursor = connection.cursor()
    cursor.execute(SQL_string)
    result = cursor.fetchone()
    connection.close()
    if result is not None:
        if result[0] == 1:
            return render_template("archive.html")
    return render_template("error.html")


if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=False)
