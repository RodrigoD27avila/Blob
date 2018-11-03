import sys
import tornado.web

import services.auth.tokenguard as ta

from log.log import error

INVALID_TOKEN_MESSAGE = "{'type': 'error','message':'token not valid'}"
VALID_TOKEN_MESSAGE   = "{'type': 'ok','message':'token valid'}"

class TokenValidatorHandler(tornado.web.RequestHandler):
	@tornado.web.asynchronous
	def get(self):
		try:
			token = self.get_argument('token')
			if (ta.valid_time(token)):
				self.write(VALID_TOKEN_MESSAGE)
			else:
				self.write(INVALID_TOKEN_MESSAGE)
		except:
			error(sys.exc_info()[0])
			self.write(INVALID_TOKEN_MESSAGE)
			self.finish()
			return

		self.finish()


