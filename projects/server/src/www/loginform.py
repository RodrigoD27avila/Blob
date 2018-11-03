import tornado.web

login_form = open("www/login.html").read()

class LoginFormHandler(tornado.web.RequestHandler):
	@tornado.web.asynchronous
	def get(self):
		self.write(login_form)
		self.finish()
		
