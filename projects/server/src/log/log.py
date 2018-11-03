import logging

from datetime import datetime

from config import logpath

logging.basicConfig(filename=logpath, format='%(asctime)-15s %(message)s')

def debug(msg):
	logging.debug(msg);

def info(msg):
	logging.info(msg);

def warning(msg):
	logging.warning(msg);

def error(msg):
	logging.error(msg);
