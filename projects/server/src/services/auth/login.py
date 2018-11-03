import sys
import tornado.web
import json
import uuid
import hashlib

import services.auth.tokengenerator as tg
import services.auth.tokenguard as ta

from dao import users
from log.log import error

INVALID_USER_MESSAGE = "{'type': 'error','message':'wrong username or password'}"

class LoginHandler(tornado.web.RequestHandler):
	@tornado.web.asynchronous
	def post(self):
		try:
			user = users.find(self.get_argument('username'))[0]
			password = hashlib.sha256(self.get_argument('password').encode()).hexdigest()
		except:
			error(sys.exc_info()[0])
			self.write(INVALID_USER_MESSAGE)
			self.finish()
			return

		if not user['password'] == password:
			self.write(INVALID_USER_MESSAGE)
			self.finish()
			return
		
		if ta.user_has_old_token(user['username']): 
			tkuuid = ta.get_user_token(user['username'])
			if not ta.valid_time(tkuuid):
				ta.remove(tkuuid)
				tg.generate_token(user['username'])
		else:
			tg.generate_token(user['username'])
		

		
		tkuuid = ta.get_user_token(user['username'])
		self.write(json.dumps({'token': tkuuid, 'user': {
				'uuid': user['uuid'],
				'name': user['name'],
				'username': user['username'],
				'lastname': user['lastname'],
				'nacionality': user['nacionality'],
				'phone': user['phone']
			}}));

		self.finish()


