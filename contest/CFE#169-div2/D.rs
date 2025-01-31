/*
    for (int i = 0; i < n; i++) {
        auto condi =
            m | filter([&](const auto &p) { return p.first != in[i] && has_same(p.first, in[i]); });
        if (auto lci = ranges::max_element(
                condi, [](const auto &a, const auto &b) { return a.second < b.second; });
            lci != ranges::end(condi)) {
            lc[i] = lci->second;
        }
        m[in[i]] = i;
    }
*/

use std::collections::HashMap;

fn has_same(a: &[char; 2], b: &[char; 2]) -> bool {
    (a[0] == b[0] || a[0] == b[1]) || (a[1] == b[0] || a[1] == b[1])
}
fn main() {

    let n : usize = 4;
    let inv : Vec<[char; 2]> = vec![['B', 'R'], ['B', 'R'], ['G', 'Y'], ['G', 'R']]; // simple
    
    let mut map : HashMap<[char; 2], i32> = HashMap::new();
    let mut lc = vec![-1; n];

    for i in 0usize..n {
        if let Some(lci) = map.iter()
            .filter(|(key, _)| *key != &inv[i] && has_same(key, &inv[i]))
            .max_by(|a, b| a.1.cmp(&b.1)) {
            lc[i] = *lci.1;
        }
        map.insert(inv[i].clone(), i as i32);
    }

    println!("{:?}", lc);
}
