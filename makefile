.PHONY : msg
msg:
	find . -name '*.msg' | xargs python tools/build_msg.py

