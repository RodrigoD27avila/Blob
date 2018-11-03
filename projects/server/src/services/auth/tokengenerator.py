import uuid

import services.auth.tokenguard as ta

def generate_token(username):
	token = str(uuid.uuid4())
	ta.insert(token, username)
	return token
