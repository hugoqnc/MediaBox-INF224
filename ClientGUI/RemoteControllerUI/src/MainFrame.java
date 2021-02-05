import java.awt.event.*;
import java.awt.BorderLayout;
import javax.swing.*;

public class MainFrame extends JFrame{

    private static final long serialVersionUID = 1L;

    private Client client;
    private JTextArea title;
    private JButton b1;
    private JButton b2;
    private JButton b3;

    public MainFrame(Client client){
        
        this.client = client;

        JPanel mainPanel = new JPanel();
        add(mainPanel);


        title = new JTextArea(10, 30);
        JScrollPane scrollableTextArea = new JScrollPane(title);  
        //scrollableTextArea.setPreferredSize(preferredSize);
        mainPanel.add(scrollableTextArea, BorderLayout.CENTER);

        JPanel buttonPanel = new JPanel();
        mainPanel.add(buttonPanel, BorderLayout.PAGE_END);

        b1 = new JButton("Search");
        buttonPanel.add(b1, BorderLayout.LINE_START);
        b1.addActionListener(new ButtonListener());

        b2 = new JButton("Play");
        buttonPanel.add(b2, BorderLayout.CENTER);
        b2.addActionListener(new ButtonListener());

        b3 = new JButton("Close");
        buttonPanel.add(b3, BorderLayout.LINE_END);
        b3.addActionListener(new ButtonListener());



        JMenuBar menuBar = new JMenuBar();
        setJMenuBar(menuBar);

        JMenu menu = new JMenu("Menu");
        menuBar.add(menu);

        JToolBar tools = new JToolBar();
        add(tools, BorderLayout.NORTH);

        ActionItem b1 = new ActionItem("Search");
        menu.add(b1);
        tools.add(b1);

        ActionItem b2 = new ActionItem("Play");
        menu.add(b2);
        tools.add(b2);

        ActionItem b3 = new ActionItem("Close");
        menu.add(b3);
        tools.add(b3);


        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }


    private class ButtonListener implements ActionListener {

        public void actionPerformed(ActionEvent e){
            if (e.getSource()==b1){
                String s = (String)JOptionPane.showInputDialog(
                    MainFrame.this,
                    "Enter the file name you want to search\n",
                    "Search",
                    JOptionPane.PLAIN_MESSAGE
                    );
                if (s!=null){title.append(client.send("search "+s));}
                
            }
            else if (e.getSource()==b2){
                String s = (String)JOptionPane.showInputDialog(
                    MainFrame.this,
                    "Enter the file name you want to play\n",
                    "Play",
                    JOptionPane.PLAIN_MESSAGE
                    );
                if (s!=null){title.append(client.send("play "+s));}
            }
            else if (e.getSource()==b3){
                MainFrame.this.dispose();
            }

        }
    }

    private class ActionItem extends AbstractAction{

        private static final long serialVersionUID = 1L;

        private String name;

        public ActionItem(String name){
            super(name);
            this.name  = name;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if (name == "Search"){
                String s = (String)JOptionPane.showInputDialog(
                    MainFrame.this,
                    "Enter the file name you want to search\n",
                    "Search",
                    JOptionPane.PLAIN_MESSAGE
                    );
                if (s!=null){title.append(client.send("search "+s));}
                
            }
            else if (name == "Play"){
                String s = (String)JOptionPane.showInputDialog(
                    MainFrame.this,
                    "Enter the file name you want to play\n",
                    "Play",
                    JOptionPane.PLAIN_MESSAGE
                    );
                if (s!=null){title.append(client.send("play "+s));}
            }
            else if (name == "Close"){
                MainFrame.this.dispose();
            }

        }
        
    }

}
