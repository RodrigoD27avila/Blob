import uuid
from hashlib import sha256

users = {
	'rodrigo': {
		'name': 'Rodrigo',
		'lastname': 'D\'avila',
		'username': 'rodrigo',
		'nationality': 'brasileiro',
		'phone': '99999999',
		'password' : sha256(b'12345678').hexdigest(),
		'uuid': str(uuid.uuid4())
	}
}
