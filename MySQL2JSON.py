#!/usr/bin/env python
# -*- coding: UTF-8 -*-

##
# @file   MySQL2JSON.py
# @brief  把MySQL的指定数据库导出成JSON格式输出
# @author 叶剑飞
# @date   2014-11-29

import sys
reload(sys)
sys.setdefaultencoding('UTF-8')

import os
import traceback
import MySQLdb
import json
import getopt

##
# @brief 把MySQL的指定数据表导出成JSON格式
#
# @param username 用户名
# @param password 密码
# @param database 数据库名
# @param host     主机名，默认值为localhost
# @param port     端口号
# @param charset  字符编码，默认值为utf8
#
# @return 成功返回JSON字符串，失败返回None
def MySQL2JSON(username, password, database, table, host="localhost", port=0, charset="utf8"):
	connection = None
	try:
		if port == 0:
			connection = MySQLdb.connect(host=host, user=username, passwd=password, db=database, charset=charset)
		else:
			connection = MySQLdb.connect(host=host, user=username, passwd=password, port=port, db=database, charset=charset)
	except:
		sys.stderr.write(traceback.format_exc())
		return None

	if connection == None:
		return None

	cursor = connection.cursor(MySQLdb.cursors.DictCursor)

	sql = 'select * from %s' % table

	try:
		cursor.execute(sql)
		results = cursor.fetchall()
	except:
		cursor.close()
		cursor = None
		connection.close()
		connection = None
		sys.stderr.write(traceback.format_exc())
		return None

	JSONEncoder = json.JSONEncoder(ensure_ascii=False, indent=4, encoding="UTF-8")
	json_string = JSONEncoder.encode(results)
	JSONEncoder = None

	cursor.close()
	cursor = None
	connection.close()
	connection = None

	return json_string

##
# @brief 把MySQL的指定数据表导出成JSON格式，并输出
#
# @param username 用户名
# @param password 密码
# @param database 数据库名
# @param host     主机名，默认值为localhost
# @param port     端口号
# @param charset  字符编码，默认值为utf8
#
# @return 成功返回0，失败返回-1
def MySQL2JSON_print(username, password, database, table, host="localhost", port=0, charset="utf8"):
	try:
		json_string = MySQL2JSON(username=username, password=password, database=database, table=table, host=host, port=port, charset=charset)
		if json_string == None:
			return -1
		print json_string
	except:
		sys.stderr.write(traceback.format_exc())
		return -1
	return 0

##
# @brief 输出帮助信息
def usage():
	print u"  -?, --help            Display this help message and exit."
	print u"  -h, --host=name       Connect to host, defaults to 'localhost'."
	print u"  -P, --port=name       Port number to use for connection, defaults to 3306."
	print u"  -u, --username=name   Username for login. (Mandatory)"
	print u"  -p, --password=name   Password for login. (Mandatory)"
	print u"  --database=name       Database name for export. (Mandatory)"
	print u"  --table=name          Table name for export. (Mandatory)"
	print u"  --charset=name        The name of the character set, defaults to 'utf8'."
	print

##
# @brief 主函数
# @param argv 命令行参数
# @return 成功返回0，失败返回非0
def main(argv):
	try:
		opts, args = getopt.gnu_getopt(argv[1:], 'h?u:p:P:', ['help', 'host=', 'username=', 'password=', 'database=', 'table=', 'port=', 'host=', 'charset='])
	except getopt.GetoptError, e:
		sys.stderr.write(e.msg+'\n')
		sys.stderr.write(u"Try '-?' or '--help' for help.\n")
		return -1
	except:
		sys.stderr.write(traceback.format_exc())
		return -1

	host = "localhost"
	port = 0
	username = None
	password = None
	charset = "utf8"
	database = None
	table = None

	for name, value in opts:
		if name in ('-?', '--help'):
			usage()
			return 0
		elif name in ('-h', '--host'):
			host = value
		elif name in ('-P', '--port'):
			port = value
		elif name in ('-u', '--username'):
			username = value
		elif name in ('-p', '--password'):
			password = value
		elif name == '--database':
			database = value
		elif name == '--table':
			table = value
		elif name == '--charset':
			charset = value
		else:
			sys.stderr.write(u'Unknown error\n')
			return -1

	if username == None:
		sys.stderr.write(u"No username given. Try '-?' or '--help' for help.\n")
		return -1
	if password == None:
		sys.stderr.write(u"No password given. Try '-?' or '--help' for help.\n")
		return -1
	if database == None:
		sys.stderr.write(u"No database name given. Try '-?' or '--help' for help.\n")
		return -1
	if table == None:
		sys.stderr.write(u"No table name given. Try '-?' or '--help' for help.\n")
		return -1

	ret = MySQL2JSON_print(username=username, password=password, database=database, table=table, host=host, port=port, charset=charset)

	if ret != 0:
		sys.stderr.write(u'Failed to export data to JSON.\n')
		return -1

	return 0

if __name__ == '__main__':
	mainret = main(sys.argv)
	os._exit(mainret)
