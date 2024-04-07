\mainpage

## Welcome

Welcome to the official ASS documentation.

## Short example

To implement your libs, you just have to do the methods specified in the proper interface, and add the entrypoint.

For example, if you want to implement the ncurs lib, you have to create your interface `RNCurses`, which inherit from `ass::IRenderer`:

```cpp
class RNCurses final : public ass::IRenderer
{
   private:
    // here add all the method you need to implement your lib

   public: // Do not add other methods in this part
    RNCurses();
    ~RNCurses() override;

    void refresh() override;
    void clear(ass::TermColor color) override;
    void set_title(std::wstring title) override;
    void draw_sprite(ass::ISprite &sprite, void *&raw_data) override;
    void free_sprite(void *&raw_data) override;
    ass::Vector2<size_t> get_window_size() const override;
    std::vector<ass::Event> events() override;
    void draw_text(ass::Vector2<float> pos, std::string text, uint size, ass::TermColor color) override;

    RNCurses(const RNCurses &) = default;
    RNCurses(RNCurses &&) = delete;
    RNCurses &operator=(const RNCurses &) = default;
    RNCurses &operator=(RNCurses &&) = delete;
};
```

Then just add the entrypoint, it must always be the same thing :

```cpp
extern "C" std::unique_ptr<ass::IRenderer> uwu_goofy_ahhh_renderer_entrypoint()
{
    return std::make_unique<RNCurses>();
}
```

Read the doc for more info about how to implement your class.
