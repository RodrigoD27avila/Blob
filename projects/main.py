import tornado.ioloop
import tornado.web

import config

class MainHandler(tornado.web.RequestHandler):
	def get(self):
		self.write('Hello Tornado')

application = tornado.web.Application([
	(r"/", MainHandler)
])

if __name__ == '__main__':
	application.listen(config.APP_SERVER_PORT)
	tornado.ioloop.IOLoop.instance().start()
		
