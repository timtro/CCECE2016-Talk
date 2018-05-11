// unit<A>(x) = std::make_optional<A>(x)

template <typename T, typename F>
auto bindM(std::optional<T> m, F f)
    -> decltype(std::invoke(f, *m)) {
  if (m)
    return std::invoke(f, *m);
  else
    return {};
}
