import zipfile,os,shutil

def check_file(filename):
	unpack_file_extension = ("exe","bat","love","md","py")
	name_list = filename.split(".")
	file_extension = name_list[-1]
	for x in unpack_file_extension:
		if x == file_extension:
			return False

	return True

def get_project_root():
	return os.path.abspath("..")

def get_project_name():
	root_path = get_project_root()
	root_list = root_path.split("\\")
	return root_list[-1]

def get_zip_extension():
	return "love"

def on_zip(root_path,file_name):
	f = zipfile.ZipFile(file_name,"w",zipfile.ZIP_DEFLATED)
	for dirpath,dirnames,filenames in os.walk(root_path):
		for filename in filenames:
			if check_file(filename):
				f.write(os.path.join(dirpath,filename),os.path.join(os.path.relpath(dirpath,root_path),filename))

	f.close()

def main():
	rootPath = get_project_root()
	projectName = get_project_name()
	zipExtension = get_zip_extension()
	filename = projectName + "." + zipExtension
	on_zip(rootPath,filename)

if __name__ == "__main__":
	main()


