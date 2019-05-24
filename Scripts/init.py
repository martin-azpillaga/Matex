import os

def main(path,units):

    blockNames = ["Definitions","Propositions","Examples","New"]

    for blockName in blockNames:

        if not os.path.exists(path+"\\"+blockName):
            os.makedirs( path+"\\"+blockName )
        f = open( path+"\\"+blockName + "\\main.tex" ,"w" )
        f.close()
        
        for unit in range(units):

            f = open( path+"\\"+blockName + "\\" + "unit " + str(unit+1) + ".tex" ,"w" )
            f.close()
        
    if not os.path.exists(path+"\\Main"): os.makedirs( path+"\\Main" )
    f = open(path+"\\Main\\main.tex","w")
    f = open(path+"\\Main\\specific.sty","w")
    f = open(path+"\\Main\\bibliography.bib","w")
    f.close()

    if not os.path.exists(path+"\\Problems"): os.makedirs( path+"\\Problems" )
    f = open(path+"\\Problems\\main.tex","w")
    f = open(path+"\\Problems\\formulations.tex","w")

    for unit in range(units):

            f = open( path+"\\Problems\\unit " + str(unit+1) + ".tex" ,"w" )
            f.close()
            
    f.close()

    if not os.path.exists(path+"\\Tasks"): os.makedirs( path+"\\Tasks" )
    f = open(path+"\\Tasks\\main.tex","w")

p= input("Path: ")
n = input("Number of units: ")
main(p,n)
