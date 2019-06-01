# dushi

- C++ library
- Python bindings
- Javascript bindings
- Chrome plugin!

```bash
$ dushi-cli "Hallo vrienden. Ik ben Martijn en ik kom uit Amersfoort. Ik verkoop mijn scooter. Hij gaat heel snel en ik rij er veel mee. Ik verkoop hem voor 100 euro."
```

> 'faFF1E brada's. 1ck ben Mart1jn En 111ck kom u1t kApo3City G. 1cK hoss3l m1jn mot0. hJ1 gaat taNtoE SneL en 1cK boeKUh er om1n VEeL mee. iiicK h0ssel hem v0' barki euri :3:3:3:3'

## Instalatie

Op deze tan2lauwe libbie gwn ff `cmake . && make` zette en met die irssi kk je `dushi-cli` gwn in `~/.irssi` jatok niet dan

## Gebruik

br0 gwn `./dushi-cli` dan je berigt in terminaal tiepe dan kryg je m tan2vers trug tok

## Python >= 3.6

`sudo python setup.py install`

```python
>>> import dushi
>>> dushi.load("path_to_dushi.db")
>>> dushi.bezem("Hallo vrienden.")
"Fawaka matties."
```

## Emscripten

Javascript :$$$

```sh
$ emcc -Isrc --embed-file dushi.db --bind -o emscripten/dushi-em.js src/dushi.cpp src/dushi-em.cpp
$ cd emscripten
$ python3 -m http.server
http://127.0.0.1:8000/dushi.html
```

```html
<!doctype html>
<html>
  <script>
    let Module = {
      onRuntimeInitialized: () => {
        console.log(Module.bezem("Hallo vrienden.", 5, 0));
      }
    };
  </script>
  <script src="dushi-em.js"></script>
</html>
```

## Chrome plugin

1. Download `fa2-voor-chrome-0.0.1.zip`
2. Unpack
3. Open Chrome
4. `chrome://extensions`
5. Developer mode
6. Load unpacked
7. Select directory: `fa2-voor-chrome`

Zelluf compilen:

```bash
$ cd chrome
$ make
```

## Irssi

Ait brada jy gebruikt irssi goed bezig btr gebruik je dese alias swa

    /alias dushi /exec - -o ~/.irssi/dushi-cli '$*'
    
## License

Jemoeder