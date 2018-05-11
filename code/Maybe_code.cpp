template <typename T, typename F>
auto bindM(std::optional<T> m, F f)
    -> decltype(std::invoke(f, *m)) {
  if (m)
    return std::invoke(f, *m);
  else
    return {};
}

std::optional<D> result = bindM(bindM(f(x), g, h));

template <typename OptionalM, typename F>
auto operator|(OptionalM &&m, F &&f){
    return bindM(std::forward<OptionalM>(m),
                 std::forward<F>(f))};

std::optional<D> result = f(x) | g | h;
