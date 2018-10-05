def id_chk(id, id_len):
	if id_len < 6 or id_len > 20:
		return -1
	if id.isnumeric():
		return -1
	if id[0].isnumeric():
		return -1
	
	flag = 0
	for i in range(0, id_len):
		if id[i] >= 'a' and id[i] <= 'z':
			flag = flag + 1
		if id[i] >= '0' and id[i] <= '9':
			flag = flag + 1
	
	if flag is not id_len:
		return -1

	return 0
	
def pw_chk(pw, pw_len):
	if pw_len < 6 or pw_len > 20:
		return -1
	if pw.isnumeric():
		return -1
	if pw[0].isnumeric():
		return -1
	
	flag = 0
	comp_flag = [0,0,0]
	for i in range(0, pw_len):
		if pw[i] >= 'a' and pw[i] <= 'z':
			flag = flag + 1
			comp_flag[0] = 1
		if pw[i] >= 'A' and pw[i] <= 'Z':
			flag = flag + 1
			comp_flag[1] = 1
		if pw[i] >= '0' and pw[i] <= '9':
			flag = flag + 1
			comp_flag[2] = 1
	
	if flag is not pw_len:
		return -1
	for i in comp_flag:
		if i is 0:
			return -1
	
	return 0

def go():
	id = input()
	pw = input()
	id_len = len(id)
	pw_len = len(pw)

	if id != pw:
		if id_chk(id, id_len) == 0 and pw_chk(pw, pw_len) == 0:
			print("Y")
			return
	
	print("N")
go()