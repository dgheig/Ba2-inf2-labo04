# labo03 - Temps

### Contributors

* Carvalho Bruno
* Gallay David

### Language

English

## Naming Conventions

* Variables: camelCase
* Functions: camelCase
* Constants: SCREAMING_SNAKE_CASE
* Type alias: PascalCase

## Compilation

1. Create directory "builds" in the project root and go inside it
2. run `cmake ..` (or `cmake .. -D DEBUG=1` for debug)
3. run `make` to compile the project

the binary will be created in {root_folder}/bin



## Documentation

Using doxygen and dot graphiz

```bash
sudo apt-get -y install doxygen texlive-latex-recommended texlive-pictures texlive-latex-extra
```

in the root folder:

```
cd doc && mkdir -p doxy && doxygen Doxyfile && make -C doxy/latex && cp doxy/latex/refman.pdf doc.pdf
```





## Usage

