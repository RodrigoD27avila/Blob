import sys
import tornado.web
import json
import uuid
import hashlib
import dao

from log.log import error

INVALID_REGISTER_MESSAGE = "{'type': 'error','message':'sorry try again'}"
VALID_REGISTER_MESSAGE = "{'type': 'ok','message':' user registration succesful'}"

class RegisterHandler(tornado.web.RequestHandler):
	@tornado.web.asynchronous
	def post(self):
		try:
			username  = self.get_argument('username')
			password1 = hashlib.sha256(self.get_argument('password').encode()).hexdigest()
			password2 = hashlib.sha256(self.get_argument('confirmation').encode()).hexdigest()
			name      = self.get_argument('name')
			lastname  = self.get_argument('lastname')
			nacionality = self.get_argument('nacionality')
			phone       = self.get_argument('phone')		

			count = dao.users.find_count(username)
			if  count >= 1 or password1 != password2:
				self.write(INVALID_REGISTER_MESSAGE)
				self.finish()
				return
		except:
			self.write(INVALID_REGISTER_MESSAGE)
			error(sys.exc_info()[0])
			self.finish()
			return
			

		dao.users.insert({
			'username': username,
			'name': name,
			'lastname': lastname,
			'nacionality': nacionality,
			'phone':  phone,
			'password':  password1,
			'uuid': str(uuid.uuid4())
			})

		self.write(VALID_REGISTER_MESSAGE);
		self.finish()
