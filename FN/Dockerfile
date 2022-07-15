FROM python:3

EXPOSE 80

RUN mkdir /app
WORKDIR /app

COPY requirements.txt /app/requirements.txt
RUN pip install -r requirements.txt

COPY . /app
RUN chmod 444 /app/users

CMD python app.py