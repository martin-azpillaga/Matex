import os

def main(path,units):

    blockNames = ["Definitions","Propositions","Examples","Exercises"]

    for blockName in blockNames:

        if not os.path.exists(path+"\\"+blockName): os.makedirs( path+"\\"+blockName )

        for unit in range(units):

            f = open( path+"\\"+blockName + "\\" + "unit " + str(unit+1) + ".tex" ,"w" )
            f.close()
        
    if not os.path.exists(path+"\\Main"): os.makedirs( path+"\\Main" )
    f = open(path+"\\Main\\main.tex","w")
    f.close()
