import os

def main():
    
    lowercase = ["A","B","C","D","E","F","G","H",
               "I","J","K","L","M","N","O","P","R","S","T","U",
               "V","W","X","Y","Z"]

    for letter in lowercase:
        
        f = open( letter + ".sublime-snippet" ,"w" )
        f.write("<snippet>\n\n<scope>text.tex.latex</scope>\n<tabTrigger>"+letter+"</tabTrigger>\n<description>.</description>\n\n<content>\n<![CDATA[\n\\"+letter+" \n]]>\n</content>\n\n</snippet>")
        f.close()
main()
