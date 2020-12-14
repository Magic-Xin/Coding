import asyncio
from Arcapi import AsyncApi

# Initialize an API with user code
api_ = AsyncApi(user_code='455704826')

# You can assign the constant range here, or just leave it in a default
asyncio.get_event_loop().run_until_complete(api_.userinfo(start=8, end=12))