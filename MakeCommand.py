import jinja2
from jinja2 import Environment, PackageLoader
from jinja2.loaders import FileSystemLoader
import sys
#takes 2 args 1st is name of the clas 2nd is whether it is hasArgs or not
if(sys.argv[2] == True):

    env = jinja2.Environment(loader=FileSystemLoader("JinjaTemplates/"))
    #Making header file
    template = env.get_template("BuiltInCommandArgs.h.jinja")

    headerFileContent = template.render(name=sys.argv[1])

    filename ="src/" + sys.argv[1] + ".h"
    with open(filename, mode="w", encoding="utf-8") as message:
        message.write(headerFileContent)
        print(f"... wrote {sys.argv[1]}")

    #Making C++ File
    template = env.get_template("BuiltInCommandArgs.cpp.jinja")

    headerFileContent = template.render(name=sys.argv[1])

    filename ="src/" + sys.argv[1] + ".cpp" 
    with open(filename, mode="w", encoding="utf-8") as message:
        message.write(headerFileContent)
        print(f"... wrote {sys.argv[1]}")
else:
    env = jinja2.Environment(loader=FileSystemLoader("JinjaTemplates/"))
    #Making header file
    template = env.get_template("BuiltInCommandNoArgs.h.jinja")

    headerFileContent = template.render(name=sys.argv[1])

    filename ="src/" + sys.argv[1] + ".h"
    with open(filename, mode="w", encoding="utf-8") as message:
        message.write(headerFileContent)
        print(f"... wrote {sys.argv[1]}")

    #Making C++ File
    template = env.get_template("BuiltInCommandNoArgs.cpp.jinja")

    headerFileContent = template.render(name=sys.argv[1])

    filename ="src/" + sys.argv[1] + ".cpp" 
    with open(filename, mode="w", encoding="utf-8") as message:
        message.write(headerFileContent)
        print(f"... wrote {sys.argv[1]}")
    


    



    
