EMCC_dir = template
SRC_dir = source

CPP_files = $(wildcard $(SRC_dir)/*.cpp)
HTML_files = $(CPP_files:$(SRC_dir)/%.cpp=%.html)

all: $(HTML_files)

%.html : $(SRC_dir)/%.cpp $(EMCC_dir)/%.html
	emcc -o $@ $< -O3 -s WASM=1 --shell-file $(EMCC_dir)/$(basename $@).html -s NO_EXIT_RUNTIME=1 -sASSERTIONS -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]'

launch : $(HTML_files)
	python -m http.server 8080

clean:
	rm -f $(HTML_files) *.js *.wasm


