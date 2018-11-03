import tornado.web

signup_form = open("www/signup.html").read()

class SignupFormHandler(tornado.web.RequestHandler):
	@tornado.web.asynchronous
	def get(self):
		self.write(signup_form)
		self.finish()
		
