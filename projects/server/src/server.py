#!/usr/bin/env python

import tornado.ioloop
import tornado.web

from tornado.options import define, options, parse_command_line

from services.auth import login
from services.auth import tokenvalidator
from services.register import register
from www import loginform, signupform

define('port', default=1600, help='run in the given port', type=int)

app = tornado.web.Application([
	(r'/'        , loginform.LoginFormHandler),
	(r'/signup'  , signupform.SignupFormHandler),
	(r'/login'   , login.LoginHandler),
	(r'/register', register.RegisterHandler),
	(r'/token'   , tokenvalidator.TokenValidatorHandler),
])

if __name__ == '__main__':
	parse_command_line()
	app.listen(options.port)
	tornado.ioloop.IOLoop.instance().start()
