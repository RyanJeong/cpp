# Notes

C++ 내용들을 정리한 디렉토리입니다.

## marp-cli

* `settings.json`

```json
// After installing the VSCode extention: marp
"markdown.marp.themes": ["./notes/theme.css"]
```

* Command

```shell
# 1. install marp-cli to use useful commands on the terminal:
npm install -g @marp-team/marp-cli

# 2. run commands on the terminal as below:
marp --pdf -w --theme ../theme.css README.md
marp --pdf --theme ../theme.css README.md
marp --pptx --theme ../theme.css README.md
```

## Index

---

## References

* [cplusplus.com](https://cplusplus.com/)
* [cppreference.com](https://en.cppreference.com/w/)
* [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
* [씹어먹는 C++](https://modoocode.com/135)
