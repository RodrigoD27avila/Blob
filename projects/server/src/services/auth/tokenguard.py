from datetime import datetime
import config

__tokens = {
	# guarda os tokens dos clientes
}

__users = {
	# guarda os clients e os tokens
}

def insert(tkuuid, username):
	__tokens[tkuuid]  = (datetime.now(), username)
	__users[username] = tkuuid

def valid_time(tkuuid):
	valid = False
	time, username = __tokens[tkuuid]
	now = datetime.now()
	if time < now:
		delta = datetime.now() - time
		valid = delta.seconds < config.TOKEN_VALID_TIME

	return valid

def user_has_old_token(username):
	return username in __users.keys()

def get_user_token(username):
	return __users[username];

def remove(tkuuid):
	time, username = __tokens[tkuuid]
	del __users[username]
	del __tokens[tkuuid]
