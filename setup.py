from distutils.core import setup, Extension

module1 = Extension(
	'c_search', # название модуля внутри Python
	 sources = ['.\\search.c'] # Исходные файлы модуля
)

setup(
	name = 'c_search',              # название модуля (my_plus.__name__)
	version = '1.0',               # версия модуля
	description = 'search module', # описание модуля
	ext_modules= [module1]         # объекты типа Extension (мы объявили его выше)
)
