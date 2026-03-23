package com.cricket;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.ui.Model;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.*;

@SpringBootApplication
@Controller
public class CricketApplication {
    
    private List<Map<String, String>> matches = new ArrayList<>();
    
    public CricketApplication() {
        Map<String, String> m1 = new HashMap<>();
        m1.put("team1", "India"); m1.put("team2", "Australia");
        m1.put("score1", "245/3"); m1.put("score2", "210/5");
        m1.put("overs", "35.2"); m1.put("status", "India needs 35 runs in 88 balls");
        matches.add(m1);
        
        Map<String, String> m2 = new HashMap<>();
        m2.put("team1", "England"); m2.put("team2", "South Africa");
        m2.put("score1", "189/7"); m2.put("score2", "156/4");
        m2.put("overs", "28.1"); m2.put("status", "England leads by 33 runs");
        matches.add(m2);
        
        Map<String, String> m3 = new HashMap<>();
        m3.put("team1", "Pakistan"); m3.put("team2", "New Zealand");
        m3.put("score1", "312/4"); m3.put("score2", "278/6");
        m3.put("overs", "50.0"); m3.put("result", "Pakistan won by 34 runs");
        matches.add(m3);
        
        Map<String, String> m4 = new HashMap<>();
        m4.put("team1", "Sri Lanka"); m4.put("team2", "Bangladesh");
        m4.put("score1", "168/2"); m4.put("score2", "145/3");
        m4.put("overs", "32.4"); m4.put("status", "Sri Lanka needs 23 runs");
        matches.add(m4);
    }
    
    @GetMapping("/")
    public String home(Model model) {
        model.addAttribute("matches", matches);
        model.addAttribute("timestamp", LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
        return "index";
    }
    
    @GetMapping("/health")
    public String health() {
        return "OK";
    }
    
    public static void main(String[] args) {
        SpringApplication.run(CricketApplication.class, args);
    }
}
