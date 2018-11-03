from persistence.mongo import database

users = database('users')

def find(user):
	return users.find({'name': {'$in': [user]}})

def find_count(user):
	cursor = find(user)
	if cursor is None:
		return 0
	return cursor.count()
		

def insert(userinfo):
	users.insert(userinfo)
