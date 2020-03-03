# Author: Tarun Govind Kesavamurthi
# School: North Carolina State University
# mail  : tkesava@ncsu.edu
#********************************************************************************#
import sys

fp = open (sys.argv[1], "r")
#fp_out = open (sys.argv[2], "w")
instruction = [] # tokens in a perticular instruction
binary_list = [] # the binary obtained after the assembly of instruction

def compute_target(target, S_ln, instn_type):
	fp = open (sys.argv[1], "r")
	tgt = "<"+target[1:]
	result = 0
	instruction = []
	instn_no = 0
	for line in fp:
		if(line.split()[0][0] != "#"):
			instn_no = instn_no + 1
		for word in line.split():
			if word[0] == "#":
				instruction.append("comment")
				break
			else :
				instruction.append(word)
		if tgt in instruction:
			result = instn_no
			break
	
	fp.close()	
	if ((result != 0) & (instn_type == "beq")):
		result = result  - (S_ln + 1)
	elif ((result != 0) & (instn_type == "j")):
		result = result - 1
	return result

def bin_string_to_int(input):
   highest_order = len(input) - 1
   result = 0
   for bit in input:
      result = result + int(bit) * pow(2,highest_order)
      highest_order = highest_order - 1
   return result

def twosComplement (value, bitLength) :
    return bin(value & (2**bitLength - 1))

instn_no = 0
for line in fp:
	#print (line.split())
	if(line.split()[0][0] != "#"):
		instn_no = instn_no + 1
	for word in line.split():
		if word[0] == "#":
			instruction.append("comment")
			break
		else :
			instruction.append(word)
	# print (instruction)
	if (instruction[0] == "add"):
		binary_list.append("000000")
		binary_list.append('{0:05b}'.format((int(instruction[2][1:]))))
		binary_list.append('{0:05b}'.format((int(instruction[3][1:]))))
		binary_list.append('{0:05b}'.format((int(instruction[1][1:]))))
		binary_list.append('{0:05b}'.format((0)))
		binary_list.append('100000')

	elif (instruction[0] == "sub"):
		binary_list.append("000000")
		binary_list.append('{0:05b}'.format((int(instruction[2][1:]))))
		binary_list.append('{0:05b}'.format((int(instruction[3][1:]))))
		binary_list.append('{0:05b}'.format((int(instruction[1][1:]))))
		binary_list.append('{0:05b}'.format((0)))
		binary_list.append('100010')

	elif (instruction[0] == "and"):
		binary_list.append("000000")
		binary_list.append('{0:05b}'.format((int(instruction[2][1:]))))
		binary_list.append('{0:05b}'.format((int(instruction[3][1:]))))
		binary_list.append('{0:05b}'.format((int(instruction[1][1:]))))
		binary_list.append('{0:05b}'.format((0)))
		binary_list.append('100100')

	elif (instruction[0] == "or"):
		binary_list.append("000000")
		binary_list.append('{0:05b}'.format((int(instruction[2][1:]))))
		binary_list.append('{0:05b}'.format((int(instruction[3][1:]))))
		binary_list.append('{0:05b}'.format((int(instruction[1][1:]))))
		binary_list.append('{0:05b}'.format((0)))
		binary_list.append('100101')

	elif (instruction[0] == "slt"):
		binary_list.append("000000")
		binary_list.append('{0:05b}'.format((int(instruction[2][1:]))))
		binary_list.append('{0:05b}'.format((int(instruction[3][1:]))))
		binary_list.append('{0:05b}'.format((int(instruction[1][1:]))))
		binary_list.append('{0:05b}'.format((0)))
		binary_list.append('101010')

	elif (instruction[0] == "lw"):
		binary_list.append("100011")
		binary_list.append('{0:05b}'.format(int(instruction[3][2:3])))
		binary_list.append('{0:05b}'.format(int(instruction[1][1:])))
		binary_list.append('{0:016b}'.format(int(instruction[2])))

	elif (instruction[0] == "sw"):
		binary_list.append("101011")
		binary_list.append('{0:05b}'.format(int(instruction[3][2:3])))
		binary_list.append('{0:05b}'.format(int(instruction[1][1:])))
		binary_list.append('{0:016b}'.format(int(instruction[2])))

	elif (instruction[0] == "beq"):
		binary_list.append("000100")
		binary_list.append('{0:05b}'.format(int(instruction[1][1:])))
		binary_list.append('{0:05b}'.format(int(instruction[2][1:])))
		# print (instn_no)
		# compute_target(instruction[4])
		tgt = compute_target(instruction[3], instn_no, "beq")
		binary_list.append('{0:016b}'.format(tgt))
	
	elif (instruction[0] == "addi"):
		binary_list.append("001000")
		binary_list.append('{0:05b}'.format(int(instruction[2][1:])))
		binary_list.append('{0:05b}'.format(int(instruction[1][1:])))
		if (instruction[3][0] == '-'): # identifying whether the numner is -ve; workaround for the shitty error
			imm = twosComplement(int(instruction[3]), 16)
			imm = imm[2:]
			binary_list.append(imm)
		else:
			binary_list.append('{0:016b}'.format(int(instruction[3])))
		
	elif (instruction[0] == "j"):
		binary_list.append("000010")
		# binary_list.append('{0:025b}'.format(int(instruction[1])))
		tgt = compute_target(instruction[1], instn_no,"j")
		binary_list.append('{0:026b}'.format(tgt))
		
	# print (binary_list)
	instn_binary_str = "".join(binary_list)
	# print (instn_binary_str)
	# print (len(instn_binary_str))
	# print (type(instn_binary_str))
	if (instruction[0] != "comment"):
		print ('{0:08X}'.format(bin_string_to_int(instn_binary_str)))
	binary_list = []
	instruction = []

fp.close()