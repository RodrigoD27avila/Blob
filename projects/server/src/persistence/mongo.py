import pymongo
from persistence.config import mongo_server, mongo_port

def client():
    return pymongo.Connection(mongo_server, mongo_port)

def database(collection):
	conn = client()
	return conn.db[collection]
