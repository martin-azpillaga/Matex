import os
for file in os.listdir(os.getcwd()):
    if file.endswith(".sublime-snippet"):
        print file
        
        with open( file , "r" ) as f:
            lines = f.readlines()

        found = False
        for line in lines:
            if line.startswith("\t<!--"):
                lines.remove(line)
            if line.startswith("\t<scope>"):
                lines[ lines.index(line) ] = "\t<scope>text.tex.latex</scope>\n"
                found = True

        if not found:
            print "no"
            for i in range(len(lines)):
                if lines[i].startswith("</snippet>"):
                    lines.append( line )
                    lines[ i ] = "\t<scope>text.tex.latex</scope>\n"

        with open(file, 'w') as f:
            f.writelines( lines )
