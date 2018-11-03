import sys
import tornado.web

class GeoLocalHandler(tornado.web.RequestHandler):
	@tornado.web.asynchronous
	def post(self):
		try:
			token = self.get_argument('token')
			lat   = self.get_argument('lat')
			lng   = selg.get_argument('lng')
			date  = self.get_argument('date')
		except:
			pass
