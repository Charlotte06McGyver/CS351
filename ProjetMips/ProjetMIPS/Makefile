# INDIQUEZ ICI: Votre nom et celui de votre binôme
AUTEURS := Nom1_Nom2

MAIN := emul-mips
SRC_C := $(wildcard src/*.c)

# Tapez "make" pour compiler le programme et produire "emul-mips".

$(MAIN): $(SRC_C)
	gcc $^ -o $@ -Wall -Wextra -O2

# Tapez "make test-cli" pour tester si vous gérez bien le mode automatique de
# la ligne de commande pour le rendu #1.

CLITMP := /tmp/emul-mips-test

test-cli: $(MAIN)
	@ [[ -e ./$(MAIN) ]] \
	  || echo "error: emul-mips does not exist!"; \
	touch $(CLITMP).in; \
	rm -f $(CLITMP).out1 $(CLITMP).out2; \
	./$(MAIN) $(CLITMP).in $(CLITMP).out1 $(CLITMP).out2 \
	  || echo "error: emul-mips in automatic mode returned $$?!"; \
	[[ -e $(CLITMP).out1 ]] \
	  || echo "error: assembled output file does not exist!"; \
	[[ -e $(CLITMP).out2 ]] \
	  || echo "error: final state output file does not exist!"; \
	rm -f $(CLITMP).out1 $(CLITMP).out2

# Tapez "make clean" pour supprimer les fichiers générés par la compilation.

clean:
	rm -f $(MAIN) src/*~ src/*.swap tests/*~ tests/*.swap
	rm -rf __pycache__ .pytest_cache tests/*.hex tests/*.state

# Tapez "make tests" pour lancer les tests.

tests: $(MAIN)
	@ python test.py -v

# Tapez "make tar" pour faire une archive du dossier avant chaque rendu.

tar: clean
	@ dir=$$(basename "$$PWD") && cd .. && tar cvfz $(AUTEURS).tgz  "$$dir"
	@ echo "==="; echo "Created ../$(AUTEURS).tgz"

.PHONY: test-cli clean tests tar
