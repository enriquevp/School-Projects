#[macro_use]
extern crate clap;
use clap::{Arg, App, SubCommand};

struct TodoItem {
    text: String,
    categories: Vec<String>
}

fn main() {
    let matches = App::new("notetake")
        .version("0.1")
        .author("Enrique Villarreal <evillarreal@protonmail.com>")
        .about("Simple todolist in rust")
        .arg(Arg::with_name("item")
             .short("a")
             .long("add")
             .help("Adds a new item to the list")
             .takes_value(true))
        .arg(Arg::with_name("categorize")
             .short("c")
             .long("category")
             .help("Specifies the category the item belongs to")
             .takes_value(true)
             .multiple(true))
        .get_matches();

    let mut v: Vec<TodoItem> = vec![];
    if matches.is_present("item") {
        let user_item = value_t!(matches.value_of("item"), String).unwrap();
        let mut added_item: TodoItem = TodoItem{text : user_item.to_string(), categories : vec![]};

        if let Some(ref categories) = matches.values_of("categorize") {
            for in_categories in categories.iter() {
                added_item.categories.push(in_categories.to_string());
           } 
        }
        v.push(added_item);
    }
    //println!("{}", v[0].text);
    //println!("{}", v[0].categories[1]);//
}
