import os

def main():
    
    lowercase = ["alpha","beta","gamma","delta","epsilon","zeta","eta","theta",
               "kappa","iota","lambda","mu","nu","xi","omicron","pi","rho","sigma","tau","upsilon",
               "phi","chi","psi","omega"]
    uppercase = ["Alpha","Beta","Gamma","Delta","Epsilon","Zeta","Eta","Theta",
               "Kappa","Iota","Lambda","Mu","Nu","Xi","Omicron","Pi","Rho","Sigma","Tau","Upsilon",
               "Phi","Chi","Psi","Omega"]

    for letter in lowercase:
        
        f = open( letter + ".sublime-snippet" ,"w" )
        f.write("<snippet>\n\n<scope>text.tex.latex</scope>\n<tabTrigger>"+letter+"</tabTrigger>\n<description>.</description>\n\n<content>\n<![CDATA[\n\\"+letter+"\n]]>\n</content>\n\n</snippet>")
        f.close()
    for letter in uppercase:
        
        f = open( "upper " + letter + ".sublime-snippet" ,"w" )
        f.write("<snippet>\n\n<scope>text.tex.latex</scope>\n<tabTrigger>"+letter+"</tabTrigger>\n<description>.</description>\n\n<content>\n<![CDATA[\n\\"+letter+"\n]]>\n</content>\n\n</snippet>")
        f.close()
main()
